pipeline {

            agent { dockerfile { filename 'Dockerfile.ROS2' } }
            stages {
                stage('build') {
                    steps {
                        sh '''
                             whoami
                             #sudo chmod -R 777 $ROS2_WS 
                             cd $ROS2_WS
                             . $ROS2_WS/install/setup.sh
 #                            colcon test 
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
