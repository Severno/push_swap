FILENAME="output.txt"
git log | grep commit | cat | awk '{ print $2 }' > $FILENAME

cd /Users/artembykov/Desktop/qs_push_swap
FILENAMECHERRY="output_cherry.txt"
git log | grep commit | cat | awk '{ print $2 }' > $FILENAMECHERRY
cp $FILENAMECHERRY /Users/artembykov/Desktop/push_swap
sh /Users/artembykov/Desktop/push_swap/get_commit_names.sh $FILENAMECHERRY > compare_cherry_log.txt
cp compare_cherry_log.txt /Users/artembykov/Desktop/push_swap
cd /Users/artembykov/Desktop/push_swap
sh /Users/artembykov/Desktop/push_swap/get_commit_names.sh $FILENAME > compare_our_log.txt



# ip=(192 168 -1 -1)

# # Step through the third quad in the array
# while [ $((ip[2]++)) -lt 255 ]; do
#     # Step through the fourth quad in the array
#     while [ $((ip[3]++)) -lt 255 ]; do
#         # Print the array, with dots as a field separator
#         IFS=. eval echo '"${ip[*]}"'
#     done
#     # Reset the last quad once we're done with this subnet
#     ip[3]=-1
# done


while read -r line;
do
	while read -r line_cherry;
	do
	if [ "$line" = "$line_cherry" ]
	then
		echo "$line" >> hello
	fi
	done < "compare_cherry_log.txt"
done < "compare_our_log.txt"

# filename="output.txt"

# for x in $(cat output.txt)
# do
# 	echo $x
# 	while read -r line;
# 	do
# 	    name="$line"
# 		if [ $x == $name ]
# 		then
# 			echo "Match $x"
# 		fi
# 	done < "output.txt"
# done
# cd /Users/artembykov/Desktop/qs_push_swap;
# 	while read -r line;
# 	do
# 	    name="$line"
# 		message=`git log --format=%B -n 1 $line`
# 		echo "$message"
# 	done < "output_cherry.txt"
# cd /Users/artembykov/Desktop/push_swap
# 	while read -r line;
# 	do
# 	    name="$line"
# 		message=`git log --format=%B -n 1 $line`
# 		echo "$message"
# 	done < "output.txt"

# git log --format=%B -n 1 76a2068828c838d19a3d804774e828be8eda9235 | cat