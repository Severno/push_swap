while read -r line;
do
    name="$line"
	message=`git log --format=%B -n 1 $line`
	echo "$message"
done < "$1"