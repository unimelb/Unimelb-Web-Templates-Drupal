(function ($) {
	Drupal.behaviors.D7UNIMELB = {
		attach: function(context, settings) {


// open

// ADD MOBILE OR NON-MOBILE CLASS TO BODY
function mobileWatch() {
	// $('#vars').html($(window).width());   // returns width of browser viewport
	// $('#vars').append(' - ' + $(document).width()); // returns width of HTML document
	if($(window).width() <= 630) {
		$('body').addClass('mobile'); $('body').removeClass('non-mobile');
	} else {
		$('body').addClass('non-mobile'); $('body').removeClass('mobile');	
		navWatch();
	}
}

// HIDE OTHER SECTIONS OF MAIN MENU IN NAV REGION
function navWatch() {
	$('.non-mobile .nav li.active-trail:first').each(function() {
		$('.nav li:not(.active-trail)').each(function() {
			if($(this).parents('li.active-trail').size() <= 0) { 
				$(this).hide(); 
			}
		});
	});
}

// ADD BUTTON CLASS TO READMORE LINKS
$('li.node-readmore:not(.readmore) a').addClass('button');

// HIDE CONTEXTUAL LINKS ON SEARCH BLOCK
$('#block-search-form > .contextual-links-wrapper > a').hide();

// mobilewatch ON RESIZE
$(window).resize(function() {
	mobileWatch();		
});

// mobileWatch ON LOAD
mobileWatch();

// navWatch ON LOAD
navWatch();

// close
		}
	};
})(jQuery);
