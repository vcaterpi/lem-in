echo ""
echo "INPUT NUMBER OF TRIALS"
read TRIALS
echo ""

COUNT=$TRIALS;
while [ "$COUNT" -gt 0 ]; do
	./gen --flow-one > graph;
	./lem-in < graph | grep algorithm;
	((COUNT--));
done