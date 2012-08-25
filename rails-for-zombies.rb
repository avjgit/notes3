# http://railsforzombies.org


#
# level 1 - CRUD
#
class Tweet {
	id
	status
	zombie
}

# retrieve
t = Tweet.find(3) 
p t[:id]		
p t[:status]
p t[:zombie]

p t.id
p t.status
p t.zombie

# class Tweet = table tweets


# CRUD:

#Create
t = Tweet.new
#! no id
t.status = "I <3 brains"
t.save

#alternate 
t2 = Tweet.new(:status => "walking around", :zombie => "Jim")
t2.save

Tweet.create(:status => "walking around", :zombie => "Jim")


#Read
Tweet.find(3) #! singular
Tweet.find(3, 4, 5)
Tweet.first
Tweet.last
Tweet.all
Tweet.count #counts on database
Tweet.order(:zombie)
Tweet.limit(10)
Tweet.where(:zombie => "ash")
Tweet.where(:zombie => "ash").order(:status).limit(10)


# Update
t = Tweet.find(3)
t.zombie = "Zad"
t.save

# alternate
Tweet.find(2)
t.attributes = {
	:status => "Can I do smth?",
	:zombie => "Zed"
}
t.save

# or even:
t3 = Tweet.find(2)
t3.update_attributes(
	:status => "somehg going on!",
	:zombie => "Zed2"
)

#Delete
t = Tweet.find(3)
t.destroy

Tweet.find(3).destroy
Tweet.destroy_all

# Try to find a Zombie where the ID is 1.
Zombie.find(1)
# Using one command, find the Zombie records with IDs 1, 2 and 3.
Zombie.find(1, 2, 3)
# Create a new Zombie.
zombie1 = Zombie.new(:name => "Zed", :graveyard => "South")
zombie1 = Zombie.create(:name => "Zed", :graveyard => "South")
# Find the last Zombie in the database, but don't use IDs
z = Zombie.last
# Find all Zombies ordered by their names.
# Zombie.all.order(:name) #?
Zombie.order(:name)
Zombie.order(:name).limit(2)
# Update Zombie 3's graveyard to 'Benny Hills Memorial'
Zombie.find(3).update_attributes(:graveyard => "Benny Hills Memorial")

Zombie.find(3).destroy

#
# level 2 - Models
# 
app/models/tweet.rb
class Tweet < ActiveRecord::Base
	validates_presence_of :status
	belongs_to :zombie #!singular
end

class Zombie < AciveRecord::Base
	has_many tweets
end

t.errors

validates_... (many options)

validates :status, :presence => true, :length => { :minimum => 3}

tweets: id, status, zombie_id

z = Zombie.find(2)
t = Tweet.create(:status=>"asdf", :zombie_id=>2)
t.zombie #returns zombie object
t.zombie.name

# Define a Zombie model.
# Add a validation that checks for the presence of a Zombie's name
# Add a validation that checks for the uniqueness of a Zombie's name.
class Zombie < ActiveRecord::Base
  attr_accessor :name, :graveyard
  validates :name, :presence => true, :uniqueness => true
end
# Use your newly created model to count the number of zombies
Zombie.count
# Verify that the validation works by trying to create a Zombie with no name
z = Zombie.new
z.save
z.errors
z.name = "Jim"
z.errors

# A Weapon belongs to a Zombie. Create that relationship.
class Weapon < ActiveRecord::Base
  belongs_to :zombie
end
# Create a weapon for an existing Zombie
w = Weapon.new(:zombie_id => 2)
w.save

# Assuming the models and relationships are properly defined, 
# find all the weapons that belong to Zombie 'Ash'.
Zombie.find(1).weapons