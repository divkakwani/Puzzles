
gcd() {
    if (($2==0))
    then
        return $1;
    else
        gcd $2 $(($1%$2))
        return $?
    fi

}

while [ 1 ]; do

    read n k

    if [ $n = -1 ]; then
        break;
    fi

    if (($k%2==0))
    then
        ans=$((($k*$k)/4 - $k/2))
    else
        ans=$(((($k-1)*($k-1))/4))
    fi

    total=$((($n*($n-1))/2))

    if [ $ans = 0 ]; then
        echo 0;
    else
        if [ $ans = $total ];
        then
            echo 1;
        else
            gcd $total $ans
            g=$?
            ans=$(($ans/$g))
            total=$(($total/$g))
            echo $ans/$total
        fi
    fi

done



