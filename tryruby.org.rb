# http://tryruby.org/levels/1/challenges/3

require 'fileutils.rb'

string = "Jimmy"
p string.reverse
p string.length
p string * 5
p 40.to_s.reverse
p "1".to_i
array = [12, 47, 35]
p array
p array.max
ticket = array
p ticket.max
p ticket.sort! #self-changin method
poem = "My toast has flown from my hand
And my toast has gone to the moon.
But when I saw it on television,
Planting our flag on Halley's comet,
More still did I want to eat it"
p poem
poem['toast'] = 'honeydew' #search and replace
p poem # just first "toast" occurence changed!
p poem.reverse
p poem.lines.to_a.reverse # or poem.bytes, poem.chars
p poem.lines.to_a.reverse.join # "join", or to_s
p poem.include? "my hand"
p poem.downcase
# poem.delete #?


books = {}
books["Gravity's Rainbow"] = :splendid # "symbol"
books["Pelevin's first"] = :quite_good
books["Pelevin's last"] = :mediocre
books["Mr.Feinman"] = :splendid # "symbol"
books["Life of Pi"] = :quite_good
books.length
p books["Gravity's Rainbow"] #:splendid
p books.keys
p books.values
ratings = Hash.new(0)


books.values.each {|rate| ratings[rate] += 1}
p ratings
5.times {print "Odelay!"}

p Dir.entries "/"
p Dir["/*.txt"]
p File.read("/asdf.txt")

FileUtils.cp('/asdf.txt', '/ruby/asdf.txt')
File.open("/ruby/asdf.txt", "a") do |f|
	f << "\nsome other comic: http://google.com"
end

p File.read("/ruby/asdf.txt")
p File.mtime("/ruby/asdf.txt")
p File.mtime("/ruby/asdf.txt").hour

def load_comics(path)
	comics = {}
	File.foreach(path) do |asdf|
		name, url = asdf.split(": ")
		# stripping extra spaces in strings
		comics[name] = url.strip 
	end
	comics	
end

p load_comics("/ruby/asdf.txt")

