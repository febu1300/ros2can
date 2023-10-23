pipeline {
        agent {
            node {
                label "localmashine"  //change this as per your agent label
            }
        }
                 
  environment {
    PACKAGE_NAME = 'ros2can'
    ROS_WORKSPACE = "${WORKSPACE}_ws"
  }
  stages {
    stage('Setup') {
      steps {
        sh 'printenv'
        sh """
          mkdir -p ${ROS_WORKSPACE}/src
          cp -R . ${ROS_WORKSPACE}/src/${PACKAGE_NAME}
        """
      }
    }
    stage('Build') {
      steps {
        dir(path: "${ROS_WORKSPACE}") {
          sh '''
            . /opt/ros/foxy/setup.sh
            colcon build 
          '''
        }
        
      }
    }
    stage('Test') {
      steps {
        dir(path: "${ROS_WORKSPACE}") {
          sh '''
            . /opt/ros/foxy/setup.sh
            colcon test
            colcon test-result --all 
             
          '''
        }
      }
    }
    stage('Sanity Check') {
      parallel {
        stage('Lint') {
          steps {
            sh '''
              . /opt/ros/foxy/setup.sh
               '''
          }
        }
        stage('Format') {
          steps {
            sh '[ -z "$(yapf --recursive --parallel --diff .)" ]'
          }
        }
      }
    }
  }
  post {
    always {
      dir(path: "${ROS_WORKSPACE}") {
        archiveArtifacts(artifacts: "**/*.log", fingerprint: true)
        junit "build/**/test_results/**/*.xml"
      }
      sh "rm -rf ${ROS_WORKSPACE}"
    }
  }
}
