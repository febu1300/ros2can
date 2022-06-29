pipeline {

            agent {
            
            	 dockerfile { filename 'Dockerfile.ROS2' } 
                 
                 }
            stages {
                 stage('Build') {
			steps {
        			
         				 sh '''
            				# . /opt/ros/foxy/setup.sh
          				 # colcon build 
          				echo $ROS2_WS
          				'''
        				
        
      				}
    			}
                stage('Test') {
                    steps {
                        sh '''
                           
                     
                             cd $ROS2_WS
                             . $ROS2_WS/install/setup.sh
                        colcon test 

	 
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
