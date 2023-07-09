class Solution {

    /**
     * @param String $text
     * @return Integer
     */
    function longestDecomposition($text) {
        $n = strlen($text);
        return $this->helper($text, 0, $n - 1, []);
    }

    function helper($text, $left, $right, &$memo) {
        if ($left > $right) {
            return 0;
        }
        if ($left == $right) {
            return 1;
        }
        if (isset($memo[$left][$right])) {
            return $memo[$left][$right];
        }

        $result = 1;
        for ($i = $left; $i < $left + (($right - $left + 1) / 2); $i++) {
            $j = $right - $i + $left;
            $suffixLen = $i - $left + 1;
            if (substr($text, $left, $suffixLen) == substr($text, $j, $suffixLen)) {
                $result = max($result, 2 + $this->helper($text, $i + 1, $j - 1, $memo));
            }
        }

        $memo[$left][$right] = $result;
        return $result;
    }
}

$text = "ghiabcdefhelloadamhelloabcdefghi";
$solution = new Solution();
$result = $solution->longestDecomposition($text);
echo $result;
