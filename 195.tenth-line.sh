#
# @lc app=leetcode id=195 lang=bash
#
# [195] Tenth Line
#

cat > file.txt <<EOF
Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10
EOF

# @lc code=start
# Read from the file file.txt and output the tenth line to stdout.

awk 'NR==10 {print}' file.txt

# @lc code=end

rm -f file.txt
