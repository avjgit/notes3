# http://ruby.hasbrains.ru/

# shop:
# items
# users
# carts

# camelcase for classes
class Item

	def initialize(options={:price => 10, :weight => 0.1})
		if options
			@price = options[:price]
			@weight = options[:weight]
		end
	end

	# # getter
	# def price
	# 	# 100
	# 	# rand(100)
	# @price
	# end

	# #setter
	# def price=(price_value)
	# 	@price = price_value
	# end
	
	#shoter!
	# attr_reader :price, :weight
	# attr_writer :price, :weight

	#even shorter!
	attr_accessor :price, :weight

end

item1 = Item.new
# item1.price=(10) @what is really going on
item1.price = 10

item2 = Item.new
item2.price = 20
item3 = Item.new({:price => 12.34, :weight => 2.5})

p item1 #<Item:0x1327e30>
p item2
p item3

p item1.price
p item2.price
p item3.price


#string vs symbols:
# in irb:
# 001 "ruby".object_id #A
# 002 "ruby".object_id #B
# 003 :ruby.object_id #C
# 004 :ruby.object_id #C

my_hash = {:name => 'James', :family_name => 'Bond'}

p my_hash[:name]