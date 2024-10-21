# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    map_generator.pl                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwillis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 10:05:17 by lwillis           #+#    #+#              #
#    Updated: 2024/10/21 10:27:42 by lwillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Run with perl map_generator.pl <columns> <rows> <density>
# Map is empty with 0 density
# Map is full with rows * 2 density
# Output to a file with > filename at the end
# The first line of the output is the legend: rows empty obstacle filled
# E.g. 9.ox = 9 rows, . empty, o obstacle, x filled

use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print "o"; # obstacle space
		}
		else {
			print "."; # empty space
		}
	}
	print "\n";
}
