package com.example.appoftheday2.view

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.fragment.app.activityViewModels
import androidx.navigation.fragment.findNavController
import com.bumptech.glide.Glide
import com.example.appoftheday2.R
import com.example.appoftheday2.databinding.FragmentFirstBinding
import com.example.appoftheday2.viewModel.ImageSet
import com.google.fragmentstest.viewmodel.CountViewModel

/**
 * A simple [Fragment] subclass as the default destination in the navigation.
 */
class FirstFragment : Fragment() {

    private var _binding: FragmentFirstBinding? = null
    private val viewModel: CountViewModel by activityViewModels()
    private val imageSetViewModel: ImageSet by activityViewModels()


    // This property is only valid between onCreateView and
    // onDestroyView.
    private val binding get() = _binding!!

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {

        _binding = FragmentFirstBinding.inflate(inflater, container, false)
        return binding.root

    }


    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        binding.NextScreenButton.setOnClickListener() {
            val dataBundle = Bundle()
            dataBundle.putInt("key", 1) // Replace with your actual data

            findNavController().navigate(
                R.id.action_FirstFragment_to_SecondFragment, dataBundle)

            Toast.makeText(requireContext(), "Fragment changed successfully", Toast.LENGTH_SHORT).show()
        }

        // lifecycleowner -> provides a way to unsubscribe when we the app / page / fragment is not used
        viewModel.getCount().observe(viewLifecycleOwner) {
            binding.countView.text = it.toString()
        }
        var imageUrl = imageSetViewModel.getImage(viewModel.getCount().value!!)
        imageUrl?.let {
            // Use the Glide library to load the image into the ImageView
            Glide
                .with(this) // Replace with your actual fragment reference
                .load(imageUrl)
                .into(binding.DownloadedImage)
        }

        binding.SetImageButtonNext.setOnClickListener {
            viewModel.increment()
            imageUrl = imageSetViewModel.getImage(viewModel.getCount().value!!)
            Glide
                .with(this)
                .load(imageUrl)
                .into(binding.DownloadedImage);

            Toast.makeText(requireContext(), "Image changed successfully", Toast.LENGTH_SHORT).show()
        }

        binding.SetImageButtonPre.setOnClickListener {
            viewModel.decrement()
            imageUrl = imageSetViewModel.getImage(viewModel.getCount().value!!)
            Glide
                .with(this)
                .load(imageUrl)
                .into(binding.DownloadedImage);

            Toast.makeText(requireContext(), "Image changed successfully", Toast.LENGTH_SHORT).show()
        }
    }


    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }
}