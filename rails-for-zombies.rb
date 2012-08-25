# http://railsforzombies.org

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