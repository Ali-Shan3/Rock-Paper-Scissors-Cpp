pipeline {
    agent any

    environment {
        GIT_CREDENTIALS_ID = 'github-pat'         // GitHub PAT credential ID
        DOCKER_CREDENTIALS_ID = 'docker-hub'      // Docker Hub credentials ID
        REPO_URL = 'https://github.com/username/django-notes-app.git'
        BRANCH = 'main'
        IMAGE_NAME = 'django-notes-app'
        IMAGE_TAG = 'latest'
        DOCKER_USER = ''                           // Will be injected from credentials
        EC2_HOST = 'ec2-user@your-ec2-public-ip'
    }

    stages {

        stage('Clone Repository') {
            steps {
                git branch: "${BRANCH}", url: "${REPO_URL}", credentialsId: "${GIT_CREDENTIALS_ID}"
            }
        }

        stage('Build Docker Image') {
            steps {
                script {
                    sh '''
                        # Make sure Jenkins can run docker
                        docker build -t ${IMAGE_NAME}:${IMAGE_TAG} .
                    '''
                }
            }
        }

        stage('Scan Docker Image') {
            steps {
                script {
                    sh '''
                        # Scan Docker image with Trivy
                        trivy image ${IMAGE_NAME}:${IMAGE_TAG}
                    '''
                }
            }
        }

        stage('Push Image to Docker Hub') {
            steps {
                withCredentials([usernamePassword(credentialsId: "${DOCKER_CREDENTIALS_ID}",
                                                 usernameVariable: 'DOCKER_USER',
                                                 passwordVariable: 'DOCKER_PASS')]) {
                    script {
                        sh '''
                            docker login -u $DOCKER_USER -p $DOCKER_PASS
                            docker tag ${IMAGE_NAME}:${IMAGE_TAG} $DOCKER_USER/${IMAGE_NAME}:${IMAGE_TAG}
                            docker push $DOCKER_USER/${IMAGE_NAME}:${IMAGE_TAG}
                        '''
                    }
                }
            }
        }

        stage('Deploy to AWS EC2') {
            steps {
                script {
                    sshagent (credentials: ['aws-ec2-ssh-key']) {
                        sh '''
                            ssh -o StrictHostKeyChecking=no ${EC2_HOST} << EOF
                                docker pull $DOCKER_USER/${IMAGE_NAME}:${IMAGE_TAG}
                                docker stop \$(docker ps -q --filter "ancestor=$DOCKER_USER/${IMAGE_NAME}:${IMAGE_TAG}") || true
                                docker rm \$(docker ps -a -q --filter "ancestor=$DOCKER_USER/${IMAGE_NAME}:${IMAGE_TAG}") || true
                                docker run -d -p 8080:8000 --name ${IMAGE_NAME} $DOCKER_USER/${IMAGE_NAME}:${IMAGE_TAG}
                            EOF
                        '''
                    }
                }
            }
        }
    }

    post {
        always {
            echo 'Pipeline finished!'
        }
    }
}
