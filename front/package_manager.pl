#!/usr/bin/env perl
use strict;
use warnings;

# Simple package manager detector for Perl

sub detect_package_manager {
    if ($^O eq 'linux') {
        return 'apt';
    } elsif ($^O =~ /bsd/) {
        return 'pkg';
    } elsif ($^O eq 'templeos') {
        die "TempleOS is unsupported\n";
    } else {
        return 'unknown';
    }
}

sub main {
    my $pm = detect_package_manager();
    print "Detected package manager: $pm\n";
}

main();
