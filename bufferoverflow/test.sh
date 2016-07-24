
while true;do

ran_num=$(( ( RANDOM % 10 )  + 1 + 5 +10))
NEW_UUID=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w $ran_num | head -n 1)
./a.out  $NEW_UUID;
echo "test";

done
