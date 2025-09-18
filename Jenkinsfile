pipeline {
    agent any

    environment {
        BRANCH = 'main'
    }

    stages {
        stage('Clone Repository') {
            steps {
                git branch: 'main', url: 'https://github.com/Ali-Shan3/Rock-Paper-Scissors-Cpp.git'

            }
        }
    }
}
