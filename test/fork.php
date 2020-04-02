<?php

	class Worker{
		
		static $address = [];

		public function run(){


			self::$address[0] = "china";

			echo "start pid=".posix_getpid()."\n";
			$pid = pcntl_fork();
			echo "pid=".posix_getpid()."address[0]:".self::$address[0]."\n";

	
			if($pid==0){
				self::$address[1] = "japanese";
				$i=0;
				//sprintf(STDOUT,"[tom] start\n");
				//echo "[tom] start\n";
				//echo "[tom] 1".self::$address[1]."\n";
				while(1){
				//	if($i==0){
				//	echo "[tom] 0 ".self::$address[$i]."\n";}
					//if(!empty(self::$address[$i])){
						set_error_handler(function(){});

						fprintf(STDOUT,"[tom] child process %d=%d,i=%d=%s\n",posix_getpid(),posix_getpgid(posix_getpid()),$i,self::$address[$i]);
						restore_error_handler();
					//	$i++;
					//}
					
					$i++;
					//echo "[tom] i=".$i."\n";
					if($i>2)$i=0;
					sleep(2);
				}
				exit(0);

			}else{
				//echo "pid=".posix_getpid()."\n";
				posix_setpgid($pid,posix_getpid());
				//echo "start second process\n";
				$pid = pcntl_fork();
				//echo "second process=".$pid."\n";
				//echo "pid=".posix_getpid()."\n";
				if($pid == 0){
					posix_setgid(posix_getpid());

					$i=0;
					self::$address[2] = "amercian";
				//	sprintf(STDOUT,"[tony] start\n");
				//	echo "[tony] start\n";
					while(1){
				//		if($i==0){
				//		echo "[tony] 0 ".self::$address[0]."\n";}
					//	if(!empty(self::$address[$i])){
							 set_error_handler(function(){});
							fprintf(STDOUT,"[tony] child process %d=%d,i=%d=%s\n",posix_getpid(),posix_getpgid(posix_getpid()),$i,self::$address[$i]);
							restore_error_handler();

							//$i++;
					//	}
						$i++;
						if($i>2)$i=0;
					//	echo "[tony] i=%d".$i."\n";
						sleep(2);
					}
					exit(0);
				}else{
					
					$status;
					$pid = pcntl_wait($status);

					echo "end".posix_getpid();
				}
			}	
		//	$pid = pcntl_wait();

		//	echo "end %d".posix_getpid();
			//posix_setgid();
		}
	
}
	$worker = new Worker();

	$worker->run();

?>
