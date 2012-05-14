<?php

// thanks to Aaron Tan and team at the Faculty of Architecture, Building and Planning, University of Melbourne, and Paul Tagell and team at Marketing and Communications, University of Melbourne - Media Insights 2011

/**
 * @file
 * theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template normally located in the
 * modules/system folder.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $hide_site_name: TRUE if the site name has been toggled off on the theme
 *   settings page. If hidden, the "element-invisible" class is added to make
 *   the site name visually hidden, but still accessible.
 * - $hide_site_slogan: TRUE if the site slogan has been toggled off on the
 *   theme settings page. If hidden, the "element-invisible" class is added to
 *   make the site slogan visually hidden, but still accessible.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 *  regions[newsbanner]	= Newsbanner
 *  regions[help]		= Help
 *  regions[content]	= Content
 *  regions[navigation]	= Navigation
 *  regions[column1]	= Column 1
 *  regions[column2]	= Column 2
 *  regions[column3]	= Column 3
 *  regions[column4]	= Column 4
 * 
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see bartik_process_page()
 */

$hide_right_column_value = 'No';
$hide_teasers_value = 'No';
$is_node = 'No';
$arg0 = arg(0);				
if(arg(0) == 'node' && is_numeric(arg(1))){ 
	
	$is_node = 'Yes';
	
	$nid = arg(1);
	$query = new EntityFieldQuery();
	$query
      ->entityCondition('entity_type', 'node')
	  ->entityCondition('entity_id', $nid);
	$result = $query->execute();
	$nids = array_keys($result['node']);
	$nodes = node_load_multiple($nids);	
		
	$hide_right_column = $nodes[$nid]->field_hide_right_column;
	if (isset($hide_right_column['und'])) {
		if($nodes[$nid]->field_hide_right_column['und'][0]['value'] == 'Yes') {
			$hide_right_column_value = 'Yes';
		} 			
	}

	$hide_teasers = $nodes[$nid]->field_hide_teasers;
	if (isset($hide_teasers['und'])) {
		if($nodes[$nid]->field_hide_teasers['und'][0]['value'] == 'Yes') {
			$hide_teasers_value = 'Yes';
		} 			
	}	
}

print render($page['header']); ?>

<div class="wrapper" id="main-wrapper">

<div class="header <?php if(variable_get('unimelb_settings_ht-right') && $is_front) { ?>with-ht<?php } else { ?>without-ht<?php } ?>">

<div class="hgroup">

<?php if(variable_get('unimelb_settings_parent-org')) { ?>
	<p>
		<?php if(variable_get('unimelb_settings_parent-org-url')) { ?>
			<a href="<?php print variable_get('unimelb_settings_parent-org-url'); ?>">
		<?php } else { ?>
			<a href="/">
		<?php } ?>
			<?php print variable_get('unimelb_settings_parent-org'); ?>
			</a>
	</p>
<?php } ?>

<h1>
	<a href="<?php print $front_page; ?>" title="Home" rel="home">
		<?php print $site_name; ?>
	</a>
</h1>

</div><!-- end hgroup -->

<?php if(variable_get('unimelb_settings_ht-right') && $is_front) { ?>
	<div id="headingtext">
		<p class="title col-2"><?php print variable_get('unimelb_settings_ht-left'); ?></p>
		<p class="col-6"><?php print variable_get('unimelb_settings_ht-right'); ?></p>
		<hr>
	</div>
<?php } ?>

</div><!-- end header -->

<div id="dropdown" class="dropdown">
	<?php $block = module_invoke('nice_menus', 'block_view', 1);
    print render($block['content']); ?>
</div><!-- end dropdown -->

<?php if ($tabs = render($tabs)): ?><div class="tabs"><?php print $tabs; ?></div><?php endif; ?>
<?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>

<?php print $messages; ?>

<?php
$newsbanner = module_invoke('views', 'block_view', 'zones_newsbanner-Newsbanner'); 
if($is_front && render($newsbanner) != '') {
	print '<div id="newsbanner">';
		print render($newsbanner); 
	print '</div><!-- end newsbanner -->';	
}
?>

<?php if ($page['above']) { print render($page['above']); } ?>
	
<div class="main col-8" id="main-content" role="main">

<?php 

if ($is_front) { 
	print '<div class="col-8 first">'; 
} else { 
	if($hide_right_column_value == 'Yes') {	
		print '<div class="col-8 first">'; 
	} else {
		print '<div class="col-6 first">'; 	
	}
} 

print render($page['content']); 

print $feed_icons; 

print '</div>'; 

if($is_front) {

if ($page['home_column1']) {
	print '<div class="col-2 first page-preview">';
	print render($page['home_column1']);
	print '</div>';
}

if ($page['home_column2']) {
	print '<div class="col-2 page-preview">';
	print render($page['home_column2']);
	print '</div>';
}

if ($page['home_column3']) {
	print '<div class="col-2 page-preview">';
	print render($page['home_column3']);
	print '</div>';
}

if ($page['home_column4']) {
	print '<div class="col-2 page-preview">';
	print render($page['home_column4']);
	print '</div>';
}
	
}

if (!$is_front && $hide_right_column_value != 'Yes') { ?>
	<div class="col-2 rightside">
		<div class="nav first polaroid" role="navigation">
		<?php $block = module_invoke('menu_block', 'block_view', 1); print render($block['content']); ?>
		<?php $block = module_invoke('search', 'block_view', 'search'); print render($block); ?>
		</div><hr /><!-- end nav -->
		<?php if($hide_teasers_value != 'Yes' && $page['aside']) { ?>
			<div class="aside" role="complementary">
			<?php print render($page['aside']); ?>
			</div><!-- end aside -->
		<?php } ?>
	</div><!-- end col-2 rightside -->	
<?php } ?>	
	
</div><!-- end main -->		
	
</div><!-- end wrapper -->

<hr />

<div class="footer">
	
<div id="local" class="wrapper">
	
<p class="footertitle"><?php print $site_name; ?></p>

<?php if(variable_get('unimelb_settings_ad-line1') || variable_get('unimelb_settings_ad-line2')) { ?><div id="org-details" class="col-2"><?php if(variable_get('unimelb_settings_parent-org')) { ?><p><strong><?php print variable_get('unimelb_settings_parent-org'); ?></strong></p><?php } ?><p class="location"><?php if(variable_get('unimelb_settings_ad-line1')) { ?><?php print variable_get('unimelb_settings_ad-line1'); ?><br><?php } ?><?php if(variable_get('unimelb_settings_ad-line2')) { ?><?php print variable_get('unimelb_settings_ad-line2'); ?><br><?php } ?><?php print variable_get('unimelb_settings_ad-sub'); ?>&nbsp;<?php print variable_get('unimelb_settings_ad-postcode'); ?>&nbsp;<?php print variable_get('unimelb_settings_ad-state'); ?>&nbsp;<?php print variable_get('unimelb_settings_ad-country'); ?></p></div><?php } ?>

<?php if (variable_get('unimelb_settings_ad-email')) { ?><ul class="col-2"><li><strong>Email:</strong> <a href="mailto:<?php print variable_get('unimelb_settings_ad-email'); ?>"><?php print variable_get('unimelb_settings_ad-email'); ?></a></li><?php if (variable_get('unimelb_settings_ad-phone')) { ?><li><strong>Phone:</strong> <?php print variable_get('unimelb_settings_ad-phone'); ?></li><?php } ?><?php if (variable_get('unimelb_settings_ad-fax')) { ?><li><strong>Fax:</strong> <?php print variable_get('unimelb_settings_ad-fax'); ?></li><?php } ?><?php if (variable_get('unimelb_settings_fb-url') || variable_get('unimelb_settings_tw-url')) { ?><li class="social"><a class="facebook" href="<?php print variable_get('unimelb_settings_fb-url'); ?>">Facebook</a>&nbsp;<a class="twitter" href="<?php print variable_get('unimelb_settings_tw-url'); ?>">Twitter</a></li><?php } ?></ul><?php } ?>

<?php if (variable_get('unimelb_settings_auth-name') || variable_get('unimelb_settings_maint-name')) { ?><ul class="col-2"><?php if (variable_get('unimelb_settings_auth-name')) { ?><li><strong>Authoriser:</strong><br><?php print variable_get('unimelb_settings_auth-name'); ?></li><?php } ?><?php if (variable_get('unimelb_settings_maint-name')) { ?><li><strong>Maintainer:</strong><br><?php print variable_get('unimelb_settings_maint-name'); ?></li><?php } ?></ul><?php } ?>

<ul class="col-2"><?php if (variable_get('unimelb_settings_date-created')) { ?><li><strong>Date created:</strong><br><?php print variable_get('unimelb_settings_date-created'); ?></li><?php } ?><li><strong>Last modified:</strong><br><?php print date('j F Y'); ?></li></ul>

<hr />

</div><!-- end local -->

</div><!-- end footer -->
