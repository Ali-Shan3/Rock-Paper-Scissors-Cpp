pipeline {
    agent any

    environment {
        BRANCH = 'main'
    }

    stages {
        stage('Clone Repository') {
            steps {
                git branch: "${BRANCH}", url: 'https://github.com/your-username/django-notes-app.git'
            }
        }
    }
}
