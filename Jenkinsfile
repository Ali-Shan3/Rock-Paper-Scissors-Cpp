pipeline {
    agent any

    environment {
        IMAGE_NAME = "rock-paper-scissors"
    }

    stages {
        stage('Checkout SCM') {
            steps {
                // Ensure repo is checked out in workspace root
                checkout([$class: 'GitSCM', 
                    branches: [[name: '*/main']], 
                    userRemoteConfigs: [[url: 'https://github.com/Ali-Shan3/Rock-Paper-Scissors-Cpp.git']]]
                )
                // Verify files exist
                sh 'ls -l'
            }
        }

        stage('Build Docker Image') {
            steps {
                // Build Docker image from workspace root
                sh 'docker build --no-cache -t $IMAGE_NAME:latest .'
            }
        }

        stage('Scan Docker Image') {
            steps {
                // Trivy vulnerability scan only, with timeout
                sh 'trivy image --scanners vuln --timeout 15m $IMAGE_NAME:latest || true'
            }
        }

        stage('Push Docker Image') {
            steps {
                withCredentials([usernamePassword(credentialsId: 'docker-cred1', usernameVariable: 'DOCKER_USER', passwordVariable: 'DOCKER_PASS')]) {
                    sh '''
                      echo "$DOCKER_PASS" | docker login -u "$DOCKER_USER" --password-stdin
                      docker tag $IMAGE_NAME:latest $DOCKER_USER/$IMAGE_NAME:latest
                      docker push $DOCKER_USER/$IMAGE_NAME:latest
                    '''
                }
            }
        }

        // Optional deploy stage (skip for now)
        // stage('Deploy to EC2') {
        //     steps {
        //         echo "Skipping deploy stage (not configured yet)"
        //     }
        // }
    }
}
