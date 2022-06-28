pipeline {
    agent none
    stages {
        stage("ros2 flow build and test") {
            agent { dockerfile { filename 'Dockerfile.ROS2' } }
            stages {
                stage('build') {
                    steps {
                        bash '''
                             cd $ROS2_WS
                             . $ROS2_WS/install/setup.bash
                             colcon build 

#                            source /opt/ros/foxy/setup.bash
	 
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
