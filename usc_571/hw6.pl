#!/usr/usc/bin/perl -w
use strict;
use warnings;
use LWP::Simple;
use CGI qw/:standard/;
use CGI qw/:standard :html3/;
use URI;
#start_html('Vegetables')

#my $buffer;
#read(STDIN, $buffer,$ENV{'QUERY_STRING'});

#use HTML::Form;
#$form = HTML::Form->parse($html, $base_uri);
#$form->value(query => "Perl");

#my @para = split(/&/,$buffer);
#my @city_temp = split(/=/,$para[0]);
#my @chain_temp = split(/=/,$para[1]);
my $city = param("city");
my $chain = param("chain");

my $url_temp = "http://www.tripadvisor.com/Search?q=${chain}+${city}";

my $url = URI->new($url_temp); 
my $content = LWP::Simple::get($url);

my @sb = ($content =~ m/<div class=\"searchResult srLODGING\">((.|\n)*?)<div class=\"crOverlayButton custom_area_QC_SearchResults  delayOpen \"/g);
#my @name = ($content =~ m/<img src=\"(.*)\" class=\"photo_image\"/g);



print header;
print "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";

my $counter = 0;
foreach (@sb){
    if($_ ne "\n"){
     $counter++;
    
    }
}

print("<hotels total=\"$counter\">\n");

foreach (@sb){
    if($_ ne "\n"){
     print("<hotel ");

     my @name = ($_ =~ m/class=\"photo_image\" style=\"(.*)\" alt=\"(.*)\"/g);
     my $the_name = $2;
     $the_name =~ s/&/&amp;/g;
     #$the_name =~ s/\//,/g;
     print (" name=\"$the_name\"");
    

     my @loc = ($_ =~ m/<span class=\"srHitType\">Hotel<\/span>\n\&ndash; (.*)<\/div>/g);    
     print(" location=\"$1\"");
    
     my @rating = ($_ =~ m/class=\"sprite-ratings\" src=\"(.*)\" alt=\"(.*) of 5 stars\"\/><\/span>\n(.*) reviews/g);
     print(" no_of_stars=\"$2\"");
     print(" no_of_reviews=\"$3\"");

     my @pic = ($_ =~ m/<img src=\"(.*)\" class=\"photo_image\"/g);
     print(" img_url=\"$1\"");

     my @href = ($_ =~ m/<div class=\"srHead\">\n<a href=\"(.*)\" onclick=/g);
     print(" review_url=\"http://www.tripadvisor.com$1\"");

     print(" />\n\n\n");
    }

}

print("</hotels>\n\n\n");

