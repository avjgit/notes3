# http://ruby.hasbrains.ru/

# shop:
# items
# users
# carts

# camelcase for classes
class Item

	def initialize(options={})
			@base_price = options[:price]
			@name = options[:name]
	end

	

	# # getter
	# def price
	# 	# 100
	# 	# rand(100)
	# @base_price
	# end

	# #setter
	# def price=(price_value)
	# 	@base_price = price_value
	# end
	
	#shoter!
	attr_reader :base_price, :name
	attr_writer :base_price

	#even shorter!
	# attr_accessor :price, :weight

	def info
		# [price, weight, name]
		# 'price is ' + price.to_s + ', weight is ' + weight.to_s 
		yield base_price
		yield name
	end

end

item1 = Item.new
# item1.price=(10) @what is really going on
item1.base_price = 10
p '--------'
p item1.info {|attr| p attr}

item2 = Item.new
item2.base_price = 20
item3 = Item.new({:price => 12.34, :weight => 2.5})

p item1 #<Item:0x1327e30>
p item2
p item3

p item1.base_price
p item2.base_price
p item3.base_price


#string vs symbols:
# in irb:
# 001 "ruby".object_id #A
# 002 "ruby".object_id #B
# 003 :ruby.object_id #C
# 004 :ruby.object_id #C

my_hash = {:name => 'James', :family_name => 'Bond'}

p my_hash[:name]
p my_hash.length

names = ['Ash', 'Bob', 'Ceazar']
p names.class
names.push 'Daedal'
p names
names.pop
p names
names << 'David'
p names
p names.shift
p names

module ItemContainer
	def add_item(item)
		@items.push item
	end
	
	def remove_item
		@items.pop
	end

	def validate
		# block - is an anonymous method
		@items.each {|item| puts(item.object_id.to_s + ' has no price') if item.base_price.nil?}
	end

	def delete_invalid_items
		#delete_if!
		@items.delete_if {|i| i.base_price.nil?}
	end
end

class Cart
	
	include ItemContainer

	attr_reader :items

	def initialize
		@items = []
	end

end

cart = Cart.new
cart.add_item(Item.new)
cart.add_item(Item.new)
p cart
cart.remove_item
p cart

names.each {|name| p name}
cart.add_item(Item.new)
cart.validate

item4 = Item.new({:price => 11, :weight => 1000, :name => 'car'})
item4.info {|attr| p attr}

2.times {p 'times method'}

person = {:first_name => 'James', :middle_name => 'X', :last_name => 'Bond'}
person.each_key {|key| p key}
person.each_key {|key| p person[key]}

# will be automatically closed
File.open("/blocks.txt", "w") {|f| f.puts 'blocks with files'}
File.open("/blocks2.txt", "w").puts( 'blocks with files 2')

item10 = Item.new({:price=>1})
item11 = Item.new

cart2 = Cart.new
cart2.add_item item10
cart2.add_item item11

p cart2.items
p cart2.delete_invalid_items
p cart2.items

class VirtualItem < Item

end

class RealItem < Item
	attr_reader :weight

	def initialize(options)
		@weight = options[:weight]
		super #calling parent initialize
	end

end

game1 = VirtualItem.new
laptop1 = RealItem.new({:weight => 0.5})

p game1.respond_to? :weight
# p game1.weight
p laptop1.weight

class Item

	@@discount = 0.1

	def self.discount
		# in december - discounts ar 30%!
		if Time.now.month == 12
			return @@discount + 0.2
		else
			return @@discount
		end
	end

	def price
		# not flexible
		# @base_price * (1 - Item.discount)
		@base_price - (@base_price * self.class.discount) + tax
	end

private
	def tax

		type_tax = if self.class == VirtualItem
			0.10
		else
			0.20
		end

		cost_tax = if @base_price > 5
			@base_price * 0.2
		else
			@base_price * 0.1
		end

		cost_tax + type_tax
	end

end

puts Item.discount
# puts game1.discount
item = Item.new
item.base_price = 100
p item.price
p item.base_price

# does not work, as this method is private
# puts item.tax


# could use inheritance from Cart, 
# but those two classes are actually not related.
# So here comes modules

class Order

	attr_reader :items

	include ItemContainer

	def initialize
		@items = Array.new
	end

	def place
		# actually place an order
	end
end


item1 = VirtualItem.new({:price => 10})
item2 = RealItem.new({:price => 1000, :weight => 0.5})
item3 = RealItem.new({:price => 1, :name => 'asdf'})

cart3 = Cart.new
cart3.add_item item1
cart3.add_item item2
cart3.add_item item3
p cart3.items.size

order1 = Order.new
order1.add_item item1
order1.add_item item2
order1.remove_item
p order1.items.size