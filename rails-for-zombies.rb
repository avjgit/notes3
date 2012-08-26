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

#
# level 3 - Views
#

zombie_twitter
- public
-- stylesheets
-- javascipts
- app
-- views
--- layouts
---- application.html.erb
--- zombies
--- tweets
---- index.html.erb #show all tweets
---- show.html.erb #show one tweet

<% %> just evaluate ruby
<%= %> eval AND print

# raw HTML
<html>
<head><title>Twitter for zombies</title></head>
<body>
	<img src = "imag.png"/>
	<% tweet = Tweet.find(1) %>
	<%= tweet.status %>
	<p>Posted by <%= tweet.zombie.name %></p>
</body></html>

# better version: separate common code (header and footer)
# .. and specific code

# app/views/layouts/application.html.erb - for header
# app/views/tweets/show.html.erb - for tweet

# app/views/layouts/application.html.erb - for header
<html>
<head>
	<title>Twitter for zombies</title>
	<%= stylesheet_link_tag :all %>
	<%= javascript_includde_tag :defaults %>
	<%= csrf_meta_tag %>
</head>
<body>
	<img src = "imag.png"/>

	#
	<%= yield %> 

</body></html>


# app/views/tweets/show.html.erb - for tweet
	<% tweet = Tweet.find(1) %>
	<%= tweet.status %>
	<p>Posted by <%= tweet.zombie.name %></p>


<p>Posted by <%= link_to tweet.zombie.name, zombie_path(tweet.zombie) %></p>
<p>Posted by <%= link_to tweet.zombie.name, tweet.zombie %></p>

# renders <a href="/zombies/1">Ash</a>


# /app/views/tweets/index.html.erb
<h1>Listing tweets</h1>
<table>
	<tr>
		<th>Status</th>
		<th>Zombie</th>
	</tr>
	<% tweets = Tweet.all %>
	<% tweets.all.each do |tweet| %>
		<tr>
			<td><%= link_to tweet.status, tweet %></td>
			<td><%= link_to tweet.zombie.name, tweet.Zombie %> </td>
			<td><%= link_to "Edit", edit_tweet_path(tweet) %> </td>
			<td><%= link_to "Delete", tweet, :method => :delete %> </td>
		</tr>
	<% end %>

	#! if no tweets yet
	<% if tweets.size == 0 %>
		<em>No tweets found</em>
	<% end %>

	<% if tweets.empty? %>
		<em>No tweets found</em>
	<% end %>

</table>

<%= link_to "text", code %>

code =
	tweets_path					= /tweets
	new_tweet_path				= /tweets/new
	tweet 						= /tweets/1
	edit_tweet_path(tweet) 		= /tweets/1/edit
	tweet, :method => :Delete 	= /tweets/1

# Print out the zombie's name and graveyard.
<h1><%= zombie.name %></h1>

<p>
  <%= zombie.graveyard %>
</p>
# Link to the zombie's show page. Use the zombie's name as the anchor text
<p>
<%= link_to zombie.name, zombie %>
</p>

# Use an each block to print the names of all the zombies.
<ul>
<% zombies.each do |zombie| %>
<%= zombie.name %>
<% end %>
</ul>

# In the each block, if a zombie has more than one tweet, print out SMART ZOMBIE.
<ul>
  <% zombies.each do |zombie| %>
    <li>
      <%= zombie.name %>
      <% if zombie.tweets.count > 1 %>
      <P>SMART ZOMBIE</P>
      <% end %>
    </li>
  <% end %>
</ul>	

# In the each block, make the zombie's name link to its edit page.
<ul>
  <% zombies.each do |zombie| %>
    <li>
      <%= link_to zombie.name, edit_zombie_path(zombie) %>
    </li>
  <% end %>
</ul>

#
# level 4 - Controllers
#

Routing --------
---------- Views
Controllers ----
---- Models ----

zombie_twitter/app/controllers/tweets_controller.rb

class TweetsController < ApplicationController
	def show
		@tweet = Tweet.find(params[:id]) #moved from show.html.erb
							   # @ - instance variable! in order View could get an access
		
		render :action => 'status'	#! where should be this line?

		# xml & json presented
		respond_to do |format|
			format.html # show.html.erb
			format.xml  {render :xml => @tweet}
			format.json {render :json => @tweet}
		end								 
	end
end
# app/views/tweets/show.html.erb - for tweet
	
	<%= @tweet.status %>
	<p>Posted by <%= @tweet.zombie.name %></p>

params = {:status => "dead"}
@tweet = Tweet.create(:status => params[:status])

params = {:tweet => {:status => 'dead'}}
@tweet = Tweet.create(:status => params[:tweet][:status])
@tweet = Tweet.create(params[:tweet])

class TweetsController < ApplicationController
	def index	#show all
	def show	#show one
	def new 	#show a new tweet form
	def edit    #show an edit tweet form
	def create #? create a new tweet
	def update #? update a tweet
	def destroy
end

class TweetsController < ApplicationController
	def edit
		@tweet = Tweet.find(params[:id])

		#! note "session"
		if session[:zombie_id] != @tweet.zombie_id
			#! flash
			flash[:notice] = "sorry, you can't edit someone else's tweet."
			redirect_to tweets_path

			#or
			redirect_to(tweets_path, :notice=> "sorry, (..)")

		end
	end
end

# if flash added in controller - then we'll need to add it in header
/app/views/layouts/application.html.erb
<body>
	#! why we need to check presence?
	<% if flash[:notice]%>
		<div id="notice"><%= flash[:notice] %></div>
	<% end %>
	<%= yield %>
</body>

# edit, update, destroy - needs authorization rights

# all edit, update, destroy - use @tweet = Tweet.find(params[:id])

# so, this line was moved out

def get_tweet
	@tweet = Tweet.find(params[:id])
end

before_filter :get_tweet, :only => [:edit, :update, :destroy]

# similarly:
def check_auth 
	if session[:zombie_id] != @tweet.zombie_id
		redirect_to(tweets_path, :notice=> "sorry, (..)")
	end
end

before_filter :check_auth, :only => [:edit, :update, :destroy]

# Create the show action for the ZombiesController which finds a Zombie based on params[:id].
class ZombiesController < ApplicationController
  def show
    @zombie = Zombie.find(params[:id])
  end
end
# Finish the respond_to block so the action returns the XML of the @zombie record
class ZombiesController < ApplicationController
  def show
    @zombie = Zombie.find(params[:id])

    respond_to do |format|
      format.xml {render :xml => @zombie}
    end
  end
end
# Write a create action that will create a new Zombie 
# from the params and then redirect to the created Zombie's show page
class ZombiesController < ApplicationController
  def create
    @zombie = Zombie.create(params[:zombie])
    redirect_to(zombie_path(@zombie))
  end
end
# Add a before filter that calls a method to check 
# if a Zombie has no tweets. Redirect to zombies_path if
# they don't have tweets, only on show

class ZombiesController < ApplicationController
  before_filter :find_zombie
  before_filter :check_tweets, :only => :show
  
  def check_tweets
    if @zombie.tweets.size == 0
      redirect_to zombies_path
    end
  end

  def show
    render :action => :show
  end

  def find_zombie
    @zombie = Zombie.find params[:id]
  end
end

#
# level 5 - Routing
#

<% =  link_to "text", <code> %>

>

code can be:
ACTION 				CODE 						generated URL
list all tweets 	tweets_path					/tweets
new tweet form 		new_tweet_path				/tweets/new
show a tweet 		tweet 						/tweets/1
edit a tweet 		edit_tweet_path(tweet) 		/tweets/1/edit
delete a tweet 		tweet, :method => :delete 	/tweets/1

zombie_twitter/config/routes.rb

ZombieTwitter::Application.routes.draw do |map|
	resources :tweets #creates RESTful resource
end

custom routes:
like,
http://localhost:3000/new_tweet renders to
http://localhost:3000/tweets/new

class TweetsController
	def new
		...
	end
end

ZombieTwitter::Application.routes.draw do |map|
	resources :tweets #creates RESTful resource
	#! to make new_tweet to render to same thing as /tweets/new
	match 'new_tweet' => 'Tweets#new' # here new_tweet is path, Tweets is controller and New is action
	
	# if you want to render same content as
	match 'all' => "Tweets#index", :as => "all_tweets" #":as => "all_tweets" allows to use it in link_to
	# if you want to redirect
	match 'all' => redirect('/tweets')

end

link_to "All tweets", all_tweets_path


root :to => "Tweets#index"

/local_tweets/32828
/local_tweets/32801
/app/controllers/tweets_controller.rb

def index
	if params[:zipcode]
		@tweets = Tweet.where(:zipcode => params[:zipcode])
	else
		@tweets = Tweet.all
	end
	respond_to do |format|
		format.html #index.html.erb

match 'local_tweets/:zipcode' => 'Tweets#index'

match ':name' => 'Tweet#index', :as => 'zombie_tweets'
<%= link_to 'Gregg', zombie_tweets_path('greggpollack')%>
>

def index
	if params[:name]
		@zombie = Zombie.where(:name => params[:name]).first
		@tweets = @zombie.tweets
	else
		@tweets = Tweet.all 
	end
end

# Create a resources route for zombies.
TwitterForZombies::Application.routes.draw do
	resources :zombies
	# Create a custom route so that '/undead' will go 
	# to the undead action on the ZombiesController.
	match 'undead' => 'zombies#undead' #! lowercase
end

# Create a redirect for '/undead' to '/zombies'.
match '/undead' => redirect('/zombies')


# Create a root route to the ZombiesController index action.
root :to => 'zombies#index'

# Create a named route. 
# It should generate a path like '/zombies/:name' 
# where :name is a parameter, and points to the index action in ZombiesController.
# Name the route 'graveyard'
match '/zombies/:name' => 'zombies#index', :as => 'graveyard'