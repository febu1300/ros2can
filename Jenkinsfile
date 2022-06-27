pipeline {
    agent none
    stages {
        stage("ros2 flow build and test") {
            agent { dockerfile { filename 'Dockerfile.ROS2' } }
            stages {
                stage('build') {
                    steps {
                        sh '''
                             cd $ROS2_WS
                             . $ROS2_WS/install/setup.sh
                             colcon build --symlink-install
   #                         colcon build --symlink-install 
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
