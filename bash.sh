git log | grep commit | cat | awk '{ print $2 }' > output.txt
cd ~; cd /Users/artembykov/Desktop/qs_push_swap; git log | grep commit | cat | awk '{ print $2 }' > output_cherry.txt;
cd /Users/artembykov/Desktop/push_swap
for x in $(cat output.txt)
do

	echo `git log --format=%B -n 1 $x`
done


# git log --format=%B -n 1 76a2068828c838d19a3d804774e828be8eda9235 | cat