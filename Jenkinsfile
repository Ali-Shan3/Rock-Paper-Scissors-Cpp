pipeline {
    agent any

    environment {
        GIT_CREDENTIALS_ID = 'github-pat' // Jenkins credential ID for GitHub PAT
        REPO_URL = 'https://github.com/Ali-Shan3/Rock-Paper-Scissors-Cpp.git'
        BRANCH = 'main'
    }

    stages {
        stage('Checkout') {
            steps {
                // Checkout repository using credentials
                git branch: "${BRANCH}", url: "${REPO_URL}", credentialsId: "${GIT_CREDENTIALS_ID}"
            }
        }

        stage('Modify Files') {
            steps {
                script {
                    // Example modification: Append a line to a file
                    sh 'echo "New line from Jenkins" >> example.txt'
                }
            }
        }

        stage('Commit Changes') {
            steps {
                script {
                    // Use credentials for git push
                    withCredentials([usernamePassword(credentialsId: "${GIT_CREDENTIALS_ID}", 
                                                     usernameVariable: 'GIT_USER', 
                                                     passwordVariable: 'GIT_TOKEN')]) {
                        sh '''
                            git config user.name "Jenkins"
                            git config user.email "jenkins@example.com"
                            git add .
                            git commit -m "Automated commit from Jenkins" || echo "No changes to commit"
                            git push https://$GIT_USER:$GIT_TOKEN@github.com/Ali-Shan3/Rock-Paper-Scissors-Cpp.git ${BRANCH}
                        '''
                    }
                }
            }
        }
    }
}
