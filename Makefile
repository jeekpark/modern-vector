clangd :
	echo "CompileFlags:" > .clangd
	echo "  Add: ['-xc++', -I$(PWD)/include, -I$(PWD), -std=c++17]" >> .clangd
	echo "  Remove : ['-xc']" >> .clangd
