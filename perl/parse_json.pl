#!/usr/bin/perl

use JSON qw(encode_json decode_json);
use Data::Dumper;

# local $/ makes open() read the whole file instead of line by line
local $/;
if ( !open (TEMPLATE, "template.json")) {
	print "failed to open the file";
}

$raw_template = <TEMPLATE>;
close TEMPLATE;

my $json = JSON->new;
my $template = $json->decode($raw_template);

print Dumper($template);
