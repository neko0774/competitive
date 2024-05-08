for x in "${'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}": do
  mkdir $x
  cd $x
  cp ../main.cpp main.cpp
  touch in out
done