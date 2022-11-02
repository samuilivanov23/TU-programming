#!/bin/bash

#sum example
((sum=12+15))
echo "$sum"

printf "\n\n"


#while loop example
valid=true
count=1
while [ $valid ]
do
	echo $count
	if [ $count -eq 5 ]
	then
		break
	fi
	((count++))
done

printf "\n\n"


#for loop example
for (( counter=10; counter>0; counter-- ))
do
	echo -n "$counter "
done

printf "\n\n"


#get user input
#echo "Enter your name: "
#read name
#echo "Welcome $name to LinuxHint"
#printf "\n\n"


#using if statement
number=10
if [[ $number -lt 10 ]]
then
	echo "It is a one digit number"
else
	echo "It is a two digit number"
fi
printf "\n\n"


#AND logic
#echo "Enter username: "
#read username
#echo "Enter password: "
#read password

#if [[ ($username == "admin") && ($password == 'supersecret') ]]; then
#	echo "Valid user"
#else
#	echo "Invalid user"
#fi
#printf "\n\n"


#OR logic
#echo "Enter number"
#read number
#if [[ ($number -eq 15) || ($number -eq 45) ]]; then
#	echo "You won the game"
#else
#	echo "You lost the game"
#fi
#printf "\n\n"


#using if else statement
#echo "Enter number"
#read number

#if [[ $number -eq 10 ]]; then
#	echo "first"
#elif [[ $number -eq 20 ]]; then
#	echo "second"
#else
#	echo "third"
#fi
#printf "\n\n"


#using case statement
#echo "Enter your lucky number"
#read lucky_num

#case $lucky_num in
#10)
#	echo "first";;
#20)
#	echo "second";;
#30)
#	echo "third";;
#*)
#	echo "default";;
#esac
#printf "\n\n"


#get arguments from command line
for arg in "$@"
do
	index=$(echo $arg | cut -d= -f1)
	value=$(echo $arg | cut -d= -f2)
	case $index in
	X)
		x=$value;;
	Y)
		y=$value;;
	*)
	esac
done
((result=x+y))
echo $result
printf "\n\n"


#Combine string vars
string1="str1"
string2="str2"

echo "$string1$string2"
string3=$string1+$string2
string3+=" some more text"
echo "$string3"
printf "\n\n"


#Add two numbers
number1=10
number2=100

((sum=number1+number2))
echo "$sum"
printf "\n\n"


#Create function
function func(){
	echo "Echo command inside function: func()"
}
func


#create new dir
#echo "Enter new directory name"
#read dir_name
#mkdir -p $dir_name
#printf "\n\n"

#read a file
file="file1"
while read line; do
	echo $line
done < $file
printf "\n\n"


#Append to file
echo "new line appended to the file" >> $file
cat $file
printf "\n\n"

#check if file exists
if [[ -f /home/student1/samuil-os/file2 ]]; then
	echo "File $file exists"
else
	echo "File $file does not exist"
fi
printf "\n\n"


