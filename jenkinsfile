pipeline {
    agent any

    environment {
        DOCKER_IMAGE = "your-dockerhub-username/your-app"
        AWS_REGION = "us-east-1"
        ECR_REPO = "123456789012.dkr.ecr.${AWS_REGION}.amazonaws.com/your-app"
    }

    stages {
        stage('Checkout SCM') {
            steps {
                git branch: 'main',
                    url: 'https://github.com/YourUser/YourRepo.git'
            }
        }

        stage('Verify Workspace') {
            steps {
                sh 'ls -la'
                sh 'echo "✅ Workspace verified"'
            }
        }

        stage('Build & Scan Docker Image') {
            steps {
                sh 'docker build -t $DOCKER_IMAGE:latest .'
                // Yahan security scan tools bhi integrate kar sakte ho (e.g. Trivy)
            }
        }

        stage('Run Container (Test)') {
            steps {
                sh 'docker run --rm -d -p 8081:8080 $DOCKER_IMAGE:latest'
            }
        }

        stage('Push to DockerHub') {
            steps {
                withCredentials([usernamePassword(credentialsId: 'dockerhub-creds', usernameVariable: 'USER', passwordVariable: 'PASS')]) {
                    sh 'echo $PASS | docker login -u $USER --password-stdin'
                    sh 'docker push $DOCKER_IMAGE:latest'
                }
            }
        }

        stage('Deploy to AWS (ECS/EKS/EC2)') {
            steps {
                sh '''
                echo "🚀 Deploying container to AWS..."
                # Yahan ap ECS task update ya EC2 par docker run command use kro
                '''
            }
        }
    }
}
