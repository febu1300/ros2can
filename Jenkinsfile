pipeline {

          agent none
                 
            stages {
            
                    stage("Fix the permission issue") {

            agent any

            steps {
                sh "sudo chown root:jenkins /run/docker.sock"
            }

        }
        

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
                 agent {
            
            	 dockerfile { filename 'Dockerfile.ROS2' } 
                 
                   }
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
