#! /bin/bash

# printf format-string args
printf "%s %d\n" "nihao" 10

# printf
printf "%-10s %-8s %-4s\n" Name Gender Weight
printf "%-10s %-8s %-4.2f\n" John Male 100.2331
printf "%-10s %-8s %-4.2f\n" Martin Female 89.121

for num in 1 2 3 4 5 6
do
    echo "Number: ${num}"
done


array=(1 2 3 4)
for num in ${array[@]}
do
    printf "Number is: %d\n" $num
done

int=1
while(( $int<=5 ))
do
    echo "$int"
    let "int++"
done

# ## 无限循环
# while :
# do
#     read film
#     echo "$film is a good movie"
# done

# echo "Byebye"
# ## 无限循环
# for (( ; ; ))
# do
#     read name 
#     echo "hello ${name}"
# done


echo '输入 1 到 4 之间的数字:'
echo '你输入的数字为:'
read aNum
case $aNum in
    1)  echo '你选择了 1'
    ;;
    2)  echo '你选择了 2'
    ;;
    3)  echo '你选择了 3'
    ;;
    4)  echo '你选择了 4'
    ;;
    *)  echo '你没有输入 1 到 4 之间的数字'
    ;;
esac