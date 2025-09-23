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

        // 🚫 Abhi ke liye comment kar diya hai
        // stage('Push Docker Image') {
        //     steps {
        //         echo "Skipping push to Docker Hub (no credentials configured yet)"
        //     }
        // }

        // stage('Deploy to EC2') {
        //     steps {
        //         echo "Skipping deploy stage (not configured yet)"
        //     }
        // }
    }
}
