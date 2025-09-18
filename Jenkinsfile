pipeline {
    agent any

    environment {
        GIT_CREDENTIALS_ID = 'your-credentials-id' // Jenkins Git credentials
        REPO_URL = 'https://github.com/username/repo.git'
        BRANCH = 'main'
    }

    stages {
        stage('Checkout') {
            steps {
                git branch: "${BRANCH}", url: "${REPO_URL}", credentialsId: "${GIT_CREDENTIALS_ID}"
            }
        }

        stage('Modify Files') {
            steps {
                script {
                    // Example: Append a line to a file
                    sh 'echo "New line from Jenkins" >> example.txt'
                }
            }
        }

        stage('Commit Changes') {
            steps {
                script {
                    sh '''
                        git config user.name "Jenkins"
                        git config user.email "jenkins@example.com"
                        git add .
                        git commit -m "Automated commit from Jenkins"
                        git push origin ${BRANCH}
                    '''
                }
            }
        }
    }
}
