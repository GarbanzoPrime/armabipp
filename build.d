/* Copyright 2013, Garbanzo Prime

    This file is part of armabipp.
    armabipp is subject to the license specified in LICENSE.txt
*/
module armabipp.build ;

import std.path ;
import tasel.tasel ;
import tasel.ext.llvm ;
import std.algorithm ;
import std.array ;

import build_config ;

private {
	immutable string[] abi_src = [
		armabipp_dir.buildPath( "src/div.cpp" ) ,
		armabipp_dir.buildPath( "src/memset.cpp" ) ,
	] ;

	immutable string[] compileFlags = [
		"-m32",
		"-nostdinc",
		"-nostdinc++",
		"-std=c++11" ,
		"-I" ~ kul_dir.buildPath("include") ,
	] ;
}

Resource buildArmABI(BuildSet tasks) {
	return tasks.addLLVMLib( abi_src , bin_dir.buildPath( "libs/armabipp.bc" ) , intermediate_dir , compileFlags ) ;	
}
