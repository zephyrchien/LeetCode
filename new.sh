#!/bin/sh

if [ $# != 2 ];then
	echo "use: new.sh [type] [number]"
	exit 0
fi

_type_=$1
_number_=$2
_dir_=''
_suffix_=''
_build_=''

case ${_type_} in 
	'c++'|'cpp'|'cc')
		_dir_='cpp'
		_suffix_='.cc'
		_build_='g++'
		;;
	'rust'|'rs')
		_dir_='rust'
		_suffix_='.rs'
		_build_='rustc'
		;;
	'js'|'javascript')
		_dir_='js'
		_suffix_='.js'
		;;
	'go'|'golang')
		_dir_='go'
		_suffix_='.go'
		_build_='go build'
		;;
	*)
		echo "not in cc/rs/js/go"
		exit 0
		;;
esac

_template_="template/0${_suffix_}"
_new_file_="${_dir_}/${_number_}${_suffix_}"
_target_="build/${_number_}"

echo "new: ${_new_file_}"
if [ -n "${_build_}" ];then
	echo "new: makefile"
else
	echo "no need to build"
fi

cp ${_template_} ${_new_file_}
cat > makefile << EOF
main: 
	${_build_} -o ${_target_} ${_new_file_}
EOF
