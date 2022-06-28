pipeline {
    agent none
    stages {
        stage("ros2 flow build and test") {
            agent { dockerfile { filename 'Dockerfile.ROS2' } }
            stages {
                stage('build') {
                    steps {
                        sh '''
                         
                             #sudo chmod -R 777 $ROS2_WS 
                             cd $ROS2_WS
                             . $ROS2_WS/install/setup.sh
                             
                             colcon build 

#                            source /opt/ros/foxy/setup.sh
	 
                       '''
                    }
                }

            }
            post {
                always {
                    deleteDir()
                }
            }
        }
    }
}
