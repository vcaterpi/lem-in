./gen --big-superposition > graph;
cp graph ../lemin_threads
echo "threads program time"
cd ../lemin_threads;
(time ./lem-in < graph) 2> file;
echo "simple program time"
cd ../lemin\ copy;
(time ./lem-in < graph) 2> file;