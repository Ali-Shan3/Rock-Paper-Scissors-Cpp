pipeline {
    agent any

    environment {
        BRANCH = 'main'
        IMAGE_NAME = 'rock-paper-scissors-cpp'
    }

    stages {
        stage('Clone Repository') {
            steps {
                git branch: "${BRANCH}", url: 'https://github.com/Ali-Shan3/Rock-Paper-Scissors-Cpp.git'
            }
        }

        stage('Build Docker Image') {
            steps {
                script {
                    sh "docker build -t ${IMAGE_NAME}:latest ."
                }
            }
        }
    }
}
