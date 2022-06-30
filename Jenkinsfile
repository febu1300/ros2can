pipeline {

             agent {
            
            	 dockerfile { filename 'Dockerfile.ROS2' } 

                   }
                 
            stages {
            
        
        

                 stage('Build') {
                   
			steps {
        			
         				 sh '''
         				# args '-u root:sudo -v $ROS2_WS:/$ROS2_WS/src/ros2pcan'
            				 . /opt/ros/foxy/setup.sh
            				        . $ROS2_WS/install/setup.sh
            				cd $ROS2_WS
          				colcon build 
          				pwd
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
