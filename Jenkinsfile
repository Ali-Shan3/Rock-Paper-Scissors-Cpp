pipeline {
    agent any

    environment {
        GIT_CREDENTIALS_ID = 'github-pat'                     // Your GitHub PAT credential ID
        DOCKER_CREDENTIALS_ID = 'docker-hub-credentials'      // Jenkins Docker Hub credentials
        REPO_URL = 'https://github.com/Ali-Shan3/Rock-Paper-Scissors-Cpp.git'
        BRANCH = 'main'
        IMAGE_NAME = 'rock-paper-scissors'
        IMAGE_TAG = 'latest'
        EC2_HOST = 'ubuntu@YOUR_EC2_PUBLIC_IP'               // Replace with your EC2 public IP
        EC2_PATH = '/home/ubuntu/app'                        // Path on EC2 to run container
    }

    stages {

        // -------------------- Stage 1: Clone Repository --------------------
        stage('Clone Repository') {
            steps {
                git branch: "${BRANCH}", url: "${REPO_URL}", credentialsId: "${GIT_CREDENTIALS_ID}"
            }
        }

        // -------------------- Stage 2: Build Docker Image --------------------
    stage('Build Docker Image') {
        steps {
            script {
                sh """
                    docker build --progress=plain --no-cache -t ${IMAGE_NAME}:${IMAGE_TAG} .
                """
            }
        }
    }

        

        // -------------------- Stage 3: Scan Image --------------------
        stage('Scan Docker Image') {
            steps {
                script {
                    sh "trivy image ${IMAGE_NAME}:${IMAGE_TAG} || true"
                }
            }
        }

        // -------------------- Stage 4: Push Image to Docker Hub --------------------
        stage('Push Docker Image') {
            steps {
                script {
                    withCredentials([usernamePassword(credentialsId: "${DOCKER_CREDENTIALS_ID}", 
                                                     usernameVariable: 'DOCKER_USER', 
                                                     passwordVariable: 'DOCKER_PASS')]) {
                        sh """
                            docker login -u $DOCKER_USER -p $DOCKER_PASS
                            docker tag ${IMAGE_NAME}:${IMAGE_TAG} $DOCKER_USER/${IMAGE_NAME}:${IMAGE_TAG}
                            docker push $DOCKER_USER/${IMAGE_NAME}:${IMAGE_TAG}
                        """
                    }
                }
            }
        }

        // -------------------- Stage 5: Deploy to AWS EC2 --------------------
        stage('Deploy to EC2') {
            steps {
                script {
                    sshagent (credentials: ['aws-ec2-ssh-key']) {
                        sh """
                            ssh -o StrictHostKeyChecking=no ${EC2_HOST} << EOF
                                docker pull $DOCKER_USER/${IMAGE_NAME}:${IMAGE_TAG}
                                docker stop ${IMAGE_NAME} || true
                                docker rm ${IMAGE_NAME} || true
                                docker run -itd --name ${IMAGE_NAME} $DOCKER_USER/${IMAGE_NAME}:${IMAGE_TAG}
                            EOF
                        """
                    }
                }
            }
        }
    }
}
