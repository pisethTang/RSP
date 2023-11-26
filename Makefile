linked: Linked_List.cpp
	@g++ Linked_List.cpp -o Linked_List
	@./Linked_List
binary: BinaryTree.cpp
	@g++ BinaryTree.cpp -o BinaryTree
	@./BinaryTree

graph: Graph.cpp
	@g++ Graph.cpp -o Graph
	@./Graph

clean_linked: 
	@rm -rf Linked_List

clean_binary:
	@rm -rf BinaryTree

clean-graph:
	@rm -rf Graph