# http://ruby.learncodethehardway.org/book/

# An 'octothorpe' is also called a 'pound', 'hash', 'mesh', or any number of names. Pick the one that makes you chill out.

cars = 100
people = 100
puts "there are #{cars} cars for #{people} available."
puts "there are %d cars for %d people available." % [cars, people]

x = "there are #{10} types of people"
binary = "binary"
do_not = "don't"
y = "Those who know #{binary} and those who #{do_not}"
puts x
puts y

puts "I said: #{x}."
puts "I also said: '#{y}'."

hilarious = false
joke_evaluation = "Isn't that joke so funny?! #{hilarious}"
puts joke_evaluation

w = "this is the left side of ..."
e = "a string with a right side."
puts w+e

formatter = "%s %s %s %s "

puts formatter % [1, 2, 3, 4]
puts formatter % ['one', 'two', 'three', 'four']
puts formatter % [true, false, false, true]
puts formatter % [formatter, formatter, formatter, formatter]

months = "Jan\nFeb"
puts months

#hm, quite interesting stuff
puts <<PARAGRAPH
asdf
sdfadsasdadsf
wewe
asda
PARAGRAPH

puts "I am 6'2\" tall"
puts 'I am 6\'2" tall'

tabbed = "\tI'm tabbed in."
split = "I'm split\non a line"
backslashed = "I'm \\ a \\ cat"
lines = <<wtf
let's make a list:
\t* food
\t* fish
\t* else\n\t* grass
wtf
puts tabbed
puts split
puts backslashed
puts lines

# print 'hey, what''s up?'
# mood = gets
# puts 'ok, I got it - ' + mood
puts '----------------'
require 'open-uri'

# open("http://www.ruby-lang.org/en") do |f|
# 	# f.each_line {|line| p line}
# 	puts f.base_uri
# 	puts f.content_type
# 	puts f.charset
# 	puts f.content_encoding
# 	puts f.last_modified
# end


first, second, third = ARGV
#very cool; you need to run the script from irb
puts "the script is called #{$0}" #! cool
puts "first is #{first}"
puts "second is #{second}"
puts "third is #{third}"

