# http://ruby.hasbrains.ru/

# shop:
# items
# users
# carts

# camelcase for classes
class Item
	def price
		# 100
		rand(100)
	end
end

item1 = Item.new
item2 = Item.new

p item1 #<Item:0x1327e30>
p item2

p item1.price
p item2.price