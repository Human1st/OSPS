<?php
if (isset($_GET['phone']))
	echo json_encode(french($_GET['phone']));

function french($number) {
    $handle = fopen("french_ranges.csv", "r");
    $dataArray = [];
    if ($handle) {
        while (($phone_range = fgets($handle)) !== false) {
            if (is_inrange($number, explode(",", $phone_range)[1], explode(",", $phone_range)[2])) {
                $dataArray = explode(",", $phone_range);
                array_push($dataArray, find_provider_name(explode(",", $phone_range)[3]));
            }
        }

        fclose($handle);
    } else {
        echo "Can't open the file";
    }
	return $dataArray;
}


function find_provider_name($code) {
    $handle = fopen("french_provider.csv", "r");
    if ($handle) {
        while (($line = fgets($handle)) !== false) {
            if (explode(",", $line)[0] == $code){
                return explode(",", $line)[1];
            }
        }

        fclose($handle);
    } else {
        echo "Can't open the file";
    } 
    return "PROVIDER_NOT_FOUND";
}

function is_inrange($phone, $rangesta, $rangesto) {
    for ($i = 0; $i != strlen($phone); $i++) {
        if ($phone[$i] < $rangesta[$i] or $phone[$i] > $rangesto[$i]) {
            return 0;
        }
    }
    return 1;
}
