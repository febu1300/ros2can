pipeline {

             agent {
            	docker{
            	 dockerfile { filename 'Dockerfile.ROS2' } 
                 args '-u root:sudo -v $ROS2_WS:/$ROS2_WS/src/ros2pcan'
                 }
                   }
                 
            stages {
            
        
        

                 stage('Build') {
                   
			steps {
        			
         				 sh '''
         				# args '-u root:sudo -v $ROS2_WS:/$ROS2_WS/src/ros2pcan'
            				# . /opt/ros/foxy/setup.sh
          				 # colcon build 
          				ls $ROS2_WS/src
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
