#!/bin/bash
# Push Swap Tester made by Arkhavy | ljohnson@student.42lyon.fr
# https://github.com/Arkhavy

big_tests()
{
	v=1
	a=1
	BEST=0
	LBEST=0
	WORST=0
	LWORST=0
	TOTAL=0
	AVERAGE=0
	N=0
	case ${x} in
		"12")	LIST=('700' '900' '1100' '1300' '1500') ;;
		"13")	LIST=('1250' '1600' '1950' '2350' '2700') ;;
		"14")	LIST=('2650' '3400' '4150' '4950' '5700') ;;
		"15")	LIST=('4000' '5200' '6350' '7550' '8700') ;;
		"16")	LIST=('5500' '7000' '8500' '10000' '11500') ;;
	esac
	# LIST="${INST_LIST[$x]}"
	printf "$BOLD$UNDERLINE\n${NLIST[$x]} digits combinations$RESET\n\n"
	while [ $v -le ${LIMIT_LIST[$x]} ]
	do
		COMB="$(sed -n ${v}p ${DCLIST[$x]})"
		CHECK="$($NAME $COMB | $CHECKER $COMB)"
		if [ $CHECK = "KO" ]
		then
			echo "CKO = $COMB" >> $FTR
			printf "$v.$CKO"
		elif [ $CHECK = "Error" ]
		then
			echo "CERR = $COMB" >> $FTR
			printf "$v.$CERR"
		else
			N="$($NAME $COMB | wc -l | tr -d ' ')"
			if [ $N -lt ${LIST[0]} ]
			then
				printf "$v.$OK5"
			elif [ $N -lt ${LIST[1]} ]
			then
				printf "$v.$OK4"
			elif [ $N -lt ${LIST[2]} ]
			then
				printf "$v.$OK3"
			elif [ $N -lt ${LIST[3]} ]
			then
				printf "$v.$OK2"
			elif [ $N -lt ${LIST[4]} ]
			then
				printf "$v.$OK1"
			else
				echo "TMI $N instructions = $COMB" >> $FTR
				printf "$v.$TMI"
			fi
			if [[ $BEST -eq 0 || $N -le $BEST ]]
			then
				BEST="$N"
				LBEST="$v"
			fi
			if [[ $WORST -eq 0 || $N -ge $WORST ]]
			then
				WORST="$N"
				LWORST="$v"
			fi
			TOTAL=$(($TOTAL + $N))
			AVERAGE=$(($TOTAL / $a))
			a=$(($a + 1))
		fi
		if [ $(($v % 10)) -eq 0 ]
		then
			printf "\n"
		else
			printf "	"
		fi
		v=$(($v + 1))
	done
	printf "\n${BOLD}BEST$RESET	$GREEN$BEST$RESET	line $LBEST"
	printf "\n${BOLD}WORST$RESET	$RED$WORST$RESET	line $LWORST"
	printf "\n${BOLD}AVERAGE$RESET	$YELLOW$AVERAGE$RESET\n"
}
