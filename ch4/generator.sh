NUM=$1
RANDOM=$$
for i in `seq $NUM`
do
		R=$(($(($RANDOM%1001))))
		echo $R >> sample1.txt
done
