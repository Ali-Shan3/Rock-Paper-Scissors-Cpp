pipeline {
    agent any

    environment {
        IMAGE_NAME = "rock-paper-scissors"
    }

    stages {
        stage('Checkout SCM') {
            steps {
                checkout scm
            }
        }

        stage('Build Docker Image') {
            steps {
                sh 'docker build --no-cache -t $IMAGE_NAME:latest .'
            }
        }

        stage('Scan Docker Image') {
            steps {
                // Trivy with longer timeout & only vuln scan
                sh 'trivy image --scanners vuln --timeout 15m $IMAGE_NAME:latest || true'
            }
        }

        stage('Push Docker Image') {
            steps {
                withCredentials([usernamePassword(credentialsId: 'docker-hub-credentials', usernameVariable: 'DOCKER_USER', passwordVariable: 'DOCKER_PASS')]) {
                    sh '''
                      echo "$DOCKER_PASS" | docker login -u "$DOCKER_USER" --password-stdin
                      docker tag $IMAGE_NAME:latest $DOCKER_USER/$IMAGE_NAME:latest
                      docker push $DOCKER_USER/$IMAGE_NAME:latest
                    '''
                }
            }
        }

        // stage('Deploy to EC2') {
        //     steps {
        //         echo "Skipping deploy stage (not configured yet)"
        //     }
        // }
    }
}
