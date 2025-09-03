#!/usr/bin/env perl
use strict;
use warnings;

# Simple Front package manager base for Perl

sub front_platform {
    if ($^O eq 'linux') {
        return 'Linux';
    } elsif ($^O =~ /bsd/) {
        return 'BSD';
    } elsif ($^O eq 'templeos') {
        return 'TempleOS';
    } else {
        return 'Unknown';
    }
}

sub main {
    my $platform = front_platform();
    print "Front package manager on $platform\n";
}

main();
