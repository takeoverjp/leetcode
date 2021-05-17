#
# @lc app=leetcode id=193 lang=bash
#
# [193] Valid Phone Numbers
#

cat <<'EOF' > file.txt
987-123-4567
123 456 7890
(123) 456-7890
EOF

# @lc code=start
# Read from the file file.txt and output all valid phone numbers to stdout.

egrep "^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$" file.txt

# @lc code=end

rm -f file.txt